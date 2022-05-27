class EJ2{
  /*
  Se desea modelar el funcionamiento de un banco en el cual existen 5 cajas para realizar
  pagos. Existen P personas que desean pagar. Para esto cada una selecciona la caja donde
  hay menos personas esperando, una vez seleccionada espera a ser atendido.
  NOTA: maximizando la concurrencia.
  Se supone que existe un metodo MINIMO que obtiene la posicion de la caja con menos gente
  */
  int P;
  cha turno(int),
      elegir_caja[N](int),
      devolver_caja(int),
      Atender[5](Pago),
      FinalizarAtencion[5](bool);
  
  process persona[id:0..P-1]{
    Pago p;
    int idCaja;
    send turno(id);
    receive elegir_caja[id](idCaja);
    send Atender[idCaja](p);
    receive FinalizarAtencion[idCaja]();
    send devolver_caja(idCaja);
  }
  process caja[id:0..4]{
    int idActual;
    Pago p;
    while(true){
      receive Atender[id](p);
      p.resolver();
      send FinalizarAtencion[id](true);
    }
  }
  process Coordinador{
    int filaEnCaja[5] = ([5] 0);
    int idActual;
    while(true){
      while (not empty(devolver_caja())){
        receive devolver_caja(idCaja);
        filaEnCaja[idCaja]--;
      }
      recive turno(idActual);
      int idCaja = minimo(filaEnCaja);
      send elegir_caja[idActual](idCaja);
      filaEnCaja[idCaja]++;
    }
  }
}