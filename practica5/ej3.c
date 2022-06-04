class ej3{
  /*
  Se dispone de un sistema compuesto por 1 central y 2 procesos. Los procesos envían
  señales a la central. La central comienza su ejecución tomando una señal del proceso 1,
  luego toma aleatoriamente señales de cualquiera de los dos indefinidamente. Al recibir una
  señal de proceso 2, recibe señales del mismo proceso durante 3 minutos.
  El proceso 1 envía una señal que es considerada vieja (se deshecha) si en 2 minutos no fue
  recibida.
  El proceso 2 envía una señal, si no es recibida en ese instante espera 1 minuto y vuelve a
  mandarla (no se deshecha).
  */
  procedure Ej3 is

  task Timer is
    Entry comenzar();
  end Timer;

  task central is
    Enty Pedido1(P: IN texto, R:IN texto);
    Enty Pedido2(P: IN texto, R:IN texto);

  task type procesos;

  arrprocesos: array (1..N) of cliente;

  Task Body central is
    proceso1Atender = true;
    begin
      accept proceso1 (P: IN texto; R:OUT texto)do
        R:= resolverPedido(P);
      end proceso1
      loop
        select
          when (proceso1Atender)=> accept proceso1 (P: IN texto; R:OUT texto)do
            R:= resolverPedido(P);
          end proceso1
        OR 
          when (timerFin''s count = 0 )=> accept proceso2 (P: IN texto; R:OUT texto)do
            if(proceso1Atender)
              R:= resolverPedido(P);
              proceso1Atender = false;
              Timer.comenzar();
            end if;
            R:= resolverPedido(P);
          end proceso2
        OR
          accept timerFin is
            proceso1Atender = true;
          end timerFin
        end select;
      end loop;
    end central;

  Task Body Timer is
  begin
    loop
      accept comenzar();
      DELAY 3min;
      central.timerFin();
    end loop
  end Timer;


  Task Body proceso1 is
  llego = false;
  begin
    loop
      P =generarSeñal();
      select
        central.Pedido1(P);
      OR DELAY 2min;
        null;
  
  Task Body proceso2 is
  begin
    P = generarSeñal();
    loop
      select central.Pedido2();
          P = generarSeñal(P);
        else
          DELAY 1min;
      end
    end if;

  end
}