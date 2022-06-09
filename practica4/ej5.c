Class Ej5{
  /*
    Resolver la administración de las impresoras de una oficina. Hay 3 impresoras, N usuarios y
    1 director. Los usuarios y el director están continuamente trabajando y cada tanto envían
    documentos a imprimir. Cada impresora, cuando está libre, toma un documento y lo
    imprime, de acuerdo al orden de llegada, pero siempre dando prioridad a los pedidos del
    director. Nota: los usuarios y el director no deben esperar a que se imprima el documento.
  */

  int N;
  cha impresionUsu(papel),
      impresionDir(papel);
  process usuario[id:0..N-1]{
    papel p;
    while(true){
      while(no tengo nada q imprimir){
        trabajo
      }
      p=tomaPapel();
      send impresionUsu(p);
    }
  }
  process director{
    papel p;
    while(true){
      while(no tengo nada q imprimir){
        trabajo
      }
      p=tomaPapel();
      send impresionDir(p);
    }
  }
  process impresora[id:0..2]{
    papel actual;
    while(true){
      if(not impresionDir.empty()){
        recieve impresionDir(actual);
        imprime(actual);
      }else if(not impresionUsu.empty()){
        recieve impresionUsu(actual);
        imprime(actual);
      }
      //imprime el papel actual
      //termino la impresion
    }
  }
}