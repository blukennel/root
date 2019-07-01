const foo = () => {
  const x = $(".p2");
  // ============= SELECTING ==================
  // $("#jakiesID");
  // $("#jakasklasa");
  // $("jakistag");
  // $(".b1 .p2").toggleClass("addon"); // el w klasie p2 w klasie b1
  // $("p.p3").toggleClass("addon"); // wsrod p element p3
  // $("p[attr='pomidor']").toggleClass("addon"); // wsrod tagow p, element w ktorym atrybut attr = 'pomidor'
  // $("[attr='cebula']").toggleClass("addon"); // wszystkie tagi gdzie attr = cebula
  // const context = $(".b1"); // zapisz w zmiennej (jako drugi argument jest JEDEN element)
  // $(".p2", context).toggleClass("addon"); // szukaj wsrod elementow nalezacych do context
  // $("[attr='fasola']", $(".b1")).toggleClass("addon"); // jak wyzej
  // $("p:first()", $(".b1")).toggleClass("addon"); // pierwszy element
  // $("p:even").toggleClass("addon"); // elementy parzyste wsrod tagow p
  // ============= TRAVERSING =================
  // x.siblings(".p3").toggleClass("addon"); // rodzenstwo elementu
  // x.parent().toggleClass("background"); // rodzic
  // x.prev().toggleClass("addon"); // poprzedni element
  // x.next().toggleClass("addon"); // nastepny element
  // $("p").last().toggleClass("addon"); // ostatni element ze zbioru
  // x.closest("div").toggleClass("background"); // najblizszy element
  // x.add(".p3").toggleClass("addon"); // dodaje jakies elementy do query
  // $(".b1").children("p").toggleClass("addon"); // potomstwo jakiegos elementu
  // $(".b2").append("<p>Hello Worlds</p>"); // dodaj html wewnatrz elementu (na koncu)

  // ============= MANIPULATING ===============
  // ...toogleClass('klasa') // dodaje klase jesli nie ma takiej, usuwa jak jest
  // ...addClass('klasa') // dodaje klase
  // ...removeClass('klasa') // usuwa klase
  // ...val() // odczytaj value elementu
  // ...val(zmienna) // zapisz value elementu
  // ...html() // odczytaj html elementu
  // ...html(zmienna) // zapisz html elementu
  // ...text() // odczytaj tekst elementu
  // ...text(zmienna) // zapisz tekst elementu

  //
  // attr() // ???
  //
};
