class EJ7{
  /*
    Suponga que existe un antivirus distribuido en él hay R procesos robots que continuamente
    están buscando posibles sitios web infectados; cada vez que encuentran uno avisan la
    dirección y continúan buscando. Hay un proceso analizador que se encargue de hacer todas
    las pruebas necesarias con cada uno de los sitios encontrados por los robots para
    determinar si están o no infectados.
  */
  process robot[i:1..R]{
    Pagina p;
    while(true){
      if(p.posibleInfectada?){
        admin!urlInfectada(p.url);
      }
    }
  }
  process analizador{
    Cola <Pagina> paginasInfectadas;
    Pagina p;
    while(true){
      admin!pedido();
      admin?paginaAnalizar(p);
      //realiza el análisis
      if(p.infectada?){
        paginasInfectadas.push(p);
      }
    }
  }

  process admin{
    Cola <Pagina> buffer;
    do robot[*]?urlInfectada(p.url) -> buffer.push(p);
    [] (notEmpty(buffer)); analizador?pedido() -> analizador!paginaAnalizar(buffer.pop());
    od
  }
}