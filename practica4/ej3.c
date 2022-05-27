class EJ3{
  /*
    Se debe modelar una casa de Comida Rápida, en el cual trabajan 2 cocineros y 3
    vendedores. Además, hay C clientes que dejan un pedido y quedan esperando a que se lo
    alcancen.
    Los pedidos que hacen los clientes son tomados por cualquiera de los vendedores y se lo
    pasan a los cocineros para que realicen el plato. Cuando no hay pedidos para atender, los
    vendedores aprovechan para reponer un pack de bebidas de la heladera (tardan entre 1 y 3
    minutos para hacer esto).
    Repetidamente cada cocinero toma un pedido pendiente dejado por los vendedores, lo
    cocina y se lo entrega directamente al cliente correspondiente.
    Nota: maximizar la concurrencia.
  */
  int C;
  cha entregarPedido(int, p), //El cliente entrega el pedido al vendedor
      recibirPedido[C](p), //El cocinero entrega el pedido del cliente
      pasarPedido(int,p), //El vendedor entrega el pedido al cocinero
      

  process cliente[id:0..C-1]{
    Pedido p;
    send entregarPedido(id, p);
    receive recibirPedido[id](p);
  }
  process cocinero[id:0..1]{
    Pedido pActual;
    int idActual;
    while(true){
      receive pasarPedido(idActual, pActual);
      pActual.cocinar();
      send recibirPedido[idActual](pActual);
    }
  }
  process vendedor[id:0..2]{
    Pedido pActual;
    int idCliente;
    while(true){
      if (not empty(entregarPedido())){
        receive entregarPedido(id, pActual);
        send pasarPedido(id, pActual);
      }else{
        //repone el pack
        sleep(1,3);
      }
    }
  }
}