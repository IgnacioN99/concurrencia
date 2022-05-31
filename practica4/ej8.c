class EJ8{
  /*
    Resolver con PMS (Pasaje de Mensajes SINCRÓNICOS) el siguiente problema. En un
    examen final hay P alumnos y 3 profesores. Cuando todos los alumnos han llegado
    comienza el examen. Cada alumno resuelve su examen, lo entrega y espera a que alguno de
    los profesores lo corrija y le indique la nota. Los profesores corrigen los exámenes
    respectando el orden en que los alumnos van entregando. Nota: maximizar la concurrencia
    y no generar demora innecesaria.
  */
  process admin{
    Cola <Examen,id> buffer;
    Examen e = nil
    int idaux,idp;
    alumnos = 0;
    while (alumnos<P){
      alumno[*]?llegue();
      alumnos++;
    } 
    while (alumnos>0){
      alumno[alumnos]!arranco(Examen.new());
      alumnos--;
    }
    for (int i=1;i<=3;i++) Profesor[i]!empezar();
    do alumno[*]?entregar(e,idaux) -> buffer.push(e,idaux);
    [] (!buffer.empty?()),profesor[*]?entregas(idp)->profesor[idp]!corregir(buffer.pop());
    od

 }
  process alumno[1..P]{
    Examen e;
    admin!llegue();
    admin?arranco(e);
    e.resolver();
    admin!entregar(e,id);
    profesor?corregido(e)
  }
  process profesor[i:1..3]{
    Examen e;
    idActual = 0;
    admin?empezar();
    cantAlumnos = 0;
    while(cantAlumnos<P){
      admin!entregas(i);
      admin?corregir(e,idActual);
      e.corregir();
      alumno[idActual]!corregido(e);
      cantAlumnos++;
    }
  }
}