# Programowanie obiektowe w C++ — materiały laboratoryjne

![C++](https://img.shields.io/badge/C%2B%2B-11-00599C?logo=cplusplus&logoColor=white)
![IDE](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-41AD48)
![Kompilator](https://img.shields.io/badge/kompilator-GCC%20%2F%20MinGW-A42E2B)
![Cel](https://img.shields.io/badge/cel-edukacyjny-informational)

Zbiór przykładów i ćwiczeń z laboratoriów ćwiczeniowych z przedmiotu pt. **Programowanie Obiektowe**.
Repozytorium prowadzi studenta krok po kroku od pierwszej klasy do małego systemu obiektów,
które współpracują ze sobą: postaci walczą, korzystają z ekwipunku i wymieniają komunikaty.

Każdy przykład ilustruje jedną z **czterech cech paradygmatu obiektowego**: abstrakcję,
hermetyzację, dziedziczenie i polimorfizm. Przez wszystkie laboratoria przewija się też piąty
temat: **komunikacja między obiektami**.

---

## Spis treści

- [Cztery filary OOP i komunikacja obiektów](#cztery-filary-oop-i-komunikacja-obiektów)
- [Mapa laboratoriów](#mapa-laboratoriów)
- [Struktura repozytorium](#struktura-repozytorium)
- [Uruchamianie](#uruchamianie)
- [Konwencje](#konwencje)
- [Jak korzystać z materiałów](#jak-korzystać-z-materiałów)

---

## Cztery filary OOP i komunikacja obiektów

| Cecha | Na czym polega | Gdzie jej szukać |
|---|---|---|
| **Abstrakcja** | Modelujemy tylko te cechy i zachowania obiektu z rzeczywistości, które są istotne dla problemu. | `Lab1` – `Osoba`, `Konto`; `Lab4–6` – `Postac`, `Przedmiot` |
| **Hermetyzacja** | Stan obiektu jest ukryty (`private`/`protected`), a zmienia się go tylko przez publiczne metody, które pilnują poprawności danych. | `Lab1/Klasy_konto` – `wplac()`/`wyplac()` z walidacją; `Lab2/DziedziczeniePolimorfiz` – poziomy dostępu `+ # -` |
| **Dziedziczenie** | Klasa pochodna przejmuje stan i zachowanie klasy bazowej i może je rozszerzać. Argumenty konstruktorów trafiają do klasy bazowej przez listę inicjalizacyjną. | `Lab2/Zwierzeta` – `Organizm → Zwierze → Owca → WilkX`; `Lab4–6` – `Postac → Czarodziej / Wojownik`, `Przedmiot → Bron / Tarcza` |
| **Polimorfizm** | Ten sam komunikat (wywołanie metody) daje różny efekt zależnie od rzeczywistego typu obiektu (`virtual`, wskaźnik na klasę bazową). | `Lab2/Zwierzeta` – tablica `Zwierze*`; `Lab2/DziedziczeniePolimorfiz` – `dajSygnal()` vs `dajSygnalZVirtual()`; `Lab6` – `virtual OpiszSie()`, `atakZaawansowany()` |
| **Komunikacja między obiektami** | Obiekty współpracują, wywołując nawzajem swoje metody i przekazując sobie referencje lub wskaźniki. Są też powiązane relacjami kompozycji i agregacji. | `Postac::zaatakuj(Postac*)`, `zaprosDoWalki()`, `przywitajSieZInnaOsoba()`; `WilkX::zjedzOwce(Owca&)`; `Postac` posiada `Plecak` i `Bron`; klasy zaprzyjaźnione `Adam` ↔ `Bartek` |

---

## Mapa laboratoriów

### Lab 1 — Klasa, obiekt, konstruktor, hermetyzacja

| Projekt | Zagadnienia |
|---|---|
| `wstepDoKlasy` | Pierwsza klasa `Osoba`: atrybuty (stan) i metody (zachowanie), przeciążanie konstruktorów, wskaźnik `this`. |
| `KlasyWstepOsoba` | Pola prywatne, setter `ustawImie()`, delegowanie konstruktorów. |
| `Klasy_wstep` | Podział klasy na plik nagłówkowy (`include/`) i implementację (`src/`), destruktor wirtualny. |
| `Klasy_konto`, `KontoBankowe` | Klasa `Konto`: hermetyzacja stanu konta, walidacja w `wplac()`/`wyplac()`, kolejność wywołań konstruktorów i destruktora. |

### Lab 2 — Dziedziczenie, polimorfizm, klasy zaprzyjaźnione

| Projekt | Zagadnienia |
|---|---|
| `DziedziczeniePolimorfiz` | Klasa `Pojazd`: dostępność `public` / `protected` / `private`, metoda zwykła i `virtual`, klasy `Silnik` i `SilnikElektryczny`. |
| `Zwierzeta` | Hierarchia `Organizm → Zwierze → Owca → WilkX` („wilk w owczej skórze”): nadpisywanie metod, wywołanie wersji z klasy bazowej, polimorfizm przez `Zwierze*`, obiekty na stosie i stercie (`new`/`delete`), znaczenie wirtualnego destruktora. |
| `klasy_zaprzyjaznione` | Słowo kluczowe `friend`: kontrolowany wyjątek od hermetyzacji (`Bartek` ma dostęp do prywatnych pól `Adama`, `Czarek` nie). |

### Lab 3 — Kolekcje obiektów

| Projekt | Zagadnienia |
|---|---|
| `MojaLista` | Własna lista jednokierunkowa `List` / `ListElement`: wskaźniki, dynamiczna alokacja, współpraca klas zaprzyjaźnionych. |
| `RozneKolekcje` | Tablice, `std::vector`, `std::list`, algorytmy STL, kontener obiektów `MyBox` (agregacja). |

### Lab 4–6 — Projekt „Postacie”: system obiektów, które ze sobą współpracują

Jeden projekt rozwijany przez trzy laboratoria. Model klas powstał najpierw jako diagram UML
(kod szkieletowy w katalogu `Class Model/`), a potem był rozbudowywany:

```
Przedmiot ──┬── Bron            Postac ──┬── Czarodziej
            └── Tarcza                   └── Wojownik

Postac ◆── Plecak ◇── Przedmiot*      Postac ── rekaLewa / rekaPrawa ──▶ Przedmiot*
```

| Etap | Co dochodzi |
|---|---|
| `Lab4` | Szkielet modelu: `Postac`, `Plecak`, `Przedmiot`, `Bron`, `Tarcza`, `Czarodziej`, `Wojownik`. |
| `Lab5` | Ekwipunek w lewej i prawej ręce, metody postaci, generator postaci, rzutowanie `dynamic_cast`. |
| `Lab6` | Walka między postaciami (`zaatakuj`, `zaprosDoWalki`, `czyTrafion`), `virtual` w `Przedmiot::OpiszSie()` i `Postac::atakZaawansowany()`, rzutowanie w stylu C `(Bron*)`, metody statyczne `losuj()` i `generujPostac()`. |

> `Lab4/test` to krótkie ćwiczenie pomocnicze w języku C.

---

## Struktura repozytorium

```
.
├── Lab1/ … Lab6/              # jeden katalog na jedno laboratorium
│   └── <Projekt>/
│       ├── <Projekt>.cbp      # projekt Code::Blocks
│       ├── main.cpp           # program demonstracyjny
│       ├── include/  src/     # nagłówki i implementacje (w większych projektach)
│       └── Class Model/       # klasy wygenerowane z modelu UML (Lab4–6)
└── README.md
```

Katalogi `bin/`, `obj/` oraz pliki `*.depend` i `*.layout` to artefakty kompilacji i IDE,
a nie kod źródłowy.

---

## Uruchamianie

### Code::Blocks (zalecane)

1. Otwórz plik `<Projekt>.cbp` wybranego projektu.
2. Wybierz cel `Debug` i uruchom **Build and run** (`F9`).

### Wiersz poleceń (GCC / MinGW)

```sh
# projekt jednoplikowy, np. Lab1/Klasy_konto
cd Lab1/Klasy_konto
g++ -Wall -std=c++11 main.cpp -o konto && ./konto

# projekt z katalogami include/ i src/, np. Lab2/Zwierzeta
cd Lab2/Zwierzeta
g++ -Wall -std=c++11 -Iinclude main.cpp src/*.cpp -o zwierzeta && ./zwierzeta

# projekt „Postacie”, np. Lab6/Postacie
cd Lab6/Postacie
g++ -Wall -std=c++11 main.cpp "Class Model"/*.cpp -o postacie && ./postacie
```

**Wymagania:** kompilator zgodny z C++11 (GCC 8+ / MinGW-w64), opcjonalnie Code::Blocks 20.03+.

---

## Konwencje

- Identyfikatory, komentarze i komunikaty są **po polsku** (`przedstawSie()`, `dajGlos()`, `zaatakuj()`).
  Dzięki temu łatwiej powiązać kod z omawianym na zajęciach modelem dziedziny.
- Komunikaty na konsoli nie zawierają polskich znaków diakrytycznych, bo w konsoli Windows
  wyświetlają się niepoprawnie.
- Kod celowo zawiera zakomentowane warianty i „ślepe uliczki”, np. błędy dostępu do pól
  prywatnych albo wywołania bez `virtual`. Służą do porównania na zajęciach:
  odkomentuj, skompiluj i zobacz, co się zmienia.

---

## Jak korzystać z materiałów

1. Przerabiaj laboratoria **po kolei**, bo każde korzysta z pojęć z poprzedniego.
2. Najpierw przeczytaj `main.cpp`, przewidź wynik działania programu, a dopiero potem go uruchom.
3. Eksperymentuj, na przykład:
   - usuń `virtual` z `Zwierze::dajGlos()` i porównaj wynik pętli po tablicy `Zwierze*`;
   - spróbuj zmienić `stan` konta z `main()` z pominięciem metod `wplac()`/`wyplac()`;
   - dodaj do projektu „Postacie” nową klasę postaci z własnym `atakZaawansowany()`.

---

*Materiały przygotowane w celach dydaktycznych dla studentów kursu Programowanie Obiektowe.*
