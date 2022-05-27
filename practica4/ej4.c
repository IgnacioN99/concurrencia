class EJ4{
  /* 
    Simular la atención en un locutorio con 10 cabinas telefónicas, que tiene un empleado que
    se encarga de atender a los clientes. Hay N clientes que al llegar esperan hasta que el
    empleado les indica a que cabina ir, la usan y luego se dirigen al empleado para pagarle. El
    empleado atiende a los clientes en el orden en que hacen los pedidos, pero siempre dando
    prioridad a los que terminaron de usar la cabina. Nota: maximizar la concurrencia; suponga
    que hay una función Cobrar() llamada por el empleado que simula que el empleado le cobra
    al cliente.
  */
  int N;
  cha pedido(int)
  cha pagar(int)
  process cliente[id:0..N-1]{
    int idCabina;
    receive pedido(idCabina);
    //usar la cabina
    send pagar(idCabina);
  }
  process empleado{
    int cabinas[10] = ([10] 0);
    while(true){
      if(empty pagar()){
        
      }
    }
  }
}