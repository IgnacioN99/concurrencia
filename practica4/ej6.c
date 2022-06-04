class EJ6{
  /*
    En un laboratorio de genética veterinaria hay 3 empleados. El primero de ellos se encarga
    de preparar las muestras de ADN lo más rápido posible; el segundo toma cada muestra de
    ADN preparada y arma el set de análisis que se deben realizar con ella y espera el resultado
    para archivarlo y continuar trabajando; el tercer empleado se encarga de realizar el análisis y
    devolverle el resultado al segundo empleado.
  */
  process primero{
    Muestra m;
    while(true){
      m.crear();
      admin!enviarMuestra(m);
    }
  }
  process segundo{
    Muestra m;
    while(true){
      admin!pedido();
      admin?enviarMuestra(m);
      //arma el set d analisis
      tercero!enviarMuestra(m);
      tercero?resultado(m);
    }
  }

  process tercero{
    Muestra m;
    while(true){
      segundo?enviarMuestra(m);
      //realiza el análisis
      segundo!resultado(m);
    }
  }

  process admin{
    Muestra actual;
    Cola <Muestra> buffer;
    do primero?enviarMuestra(actual) -> buffer.push(actual);
    [] (notEmpty(buffer)); segundo?pedido() -> segundo!enviarMuestra(buffer.pop());
    od
  }
}