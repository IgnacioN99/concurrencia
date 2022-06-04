class ej2{
  /*
    Se quiere modelar la cola de un banco que atiende un solo empleado, los clientes llegan y si
    esperan más de 10 minutos se retiran.
  */
  procedure Ej2 is
  task empleado is
    Enty Pedido(P: IN texto, R:IN texto);

  task type cliente;

  arrCliente: array (1..N) of cliente;

  Task Body empleado is
    begin
      loop
        accept Pedido (P: IN texto; R:OUT texto)do
          R:= resolverPedido(P);
        end Pedido
      end loop;
    end empleado;

  Task Body cliente is
  begin
    select
      empleado.Pedido(P,R);
    OR DELAY 10min;
      NULL;
    end select
  end
}