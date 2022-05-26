class EJ1 {
  /*1
  Suponga que N personas llegan a la cola de un banco. Para atender a las personas existen 2
  empleados que van atendiendo de a una y por orden de llegada a las personas.
  */ 
  int N;
  cha llegada(int);
  cha atender[2](pedido);
  cha espera[N](int);

  process personas[id:0..N-1]{
    int idEmpleado;
    pedido p;
    send llegada(id);
    receive espera[id](idEmpleado);
    send atender[idEmpleado](p);
    receive espera[id](idEmpleado);
  }
  process empleado[id:0..1]{
    int idActual;
    pedido p;
    while(true){
      receive llegada(idActual);
      send espera[idActual](id);
      receive atender[id](p);
      p.resolver();
      send espera[idActual](id);
    }
  }
}
class EJ2{
  /*
  Se desea modelar el funcionamiento de un banco en el cual existen 5 cajas para realizar
  pagos. Existen P personas que desean pagar. Para esto cada una selecciona la caja donde
  hay menos personas esperando, una vez seleccionada espera a ser atendido.
  NOTA: maximizando la concurrencia.
  */
  int P;
  process persona[id:0..P-1]{

  }
  process caja[id:0..5]{
    
  }
}