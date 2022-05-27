Class Ej5{
  /*
    Resolver la administración de las impresoras de una oficina. Hay 3 impresoras, N usuarios y
    1 director. Los usuarios y el director están continuamente trabajando y cada tanto envían
    documentos a imprimir. Cada impresora, cuando está libre, toma un documento y lo
    imprime, de acuerdo al orden de llegada, pero siempre dando prioridad a los pedidos del
    director. Nota: los usuarios y el director no deben esperar a que se imprima el documento.
  */

  int N;
  
  process usuario[id:0..N-1]{

  }
  process director{

  }
  process administración{

  }
  process impresora[id:0..2]{

  }
}