# Sandbox hra
Autor: Bohdan Vradii
## Téma z Progtestu
Naprogramujte jednoduchou 2D sandbox hru.

Hra musí splňovat následující funkcionality

1) Implementujte hráče (postava, loď, ...) a jeho stav (energie, životy, brnění, skore, ...)
2) Vytvořte (soubojový) model zranění - alespoň dvě příčiny (pád z výšky, soubor s nepřítelem, pobyt v lávě, ...)
3) Vytvořte jednoduchý model prostředí (gravitace, přelévání vody (lávy), růst stromů, ...)
4) Naimplementujte načítání (konfigurace generátoru) mapy ze souboru a umožněte ukládat aktuální stav hry.

Kde lze využít polymorfismus? (doporučené)

- Postavy: hráč, zvířata, přítel (obchodník), nepřítel (různé druhy)
- Efekty akcí: pád, úder, kontakt s lávou
- Prostředí: vzduch, voda, hlína, uhlí, kov, láva, žebřík,...
- Uživatelské rozhraní: konzole, ncurses, SDL, OpenGL (různé varianty), ...


## Implementace Hry

Vytvoříme hru "Forest run", uživatel spustí hru pomocí následujících příkazů v konzole"

- `vradiboh.exe [mapname]` načíst hru ze souboru
- `forrun.exe` vytvoří novou hru se standardními parametrynačíst hru ze souboru
Během běžící hry:
- `p` uloží hru do souboru
- `a` posunout hráče doleva
- `d` posunout hráče doprava.
- `w` skok ve směru pohybu hráče
- `e` zaútočit na nepřítele
- `h` zobrazí nápovědu
- `q` ukončí program

```
_____________________
|        ~         ~|
|        ~~        ~|
|~~ ~~~~   ~~~~~~~  |
|              ~~~~~|
| ~ ~ ~ ~ ~ ~ ~ ~ ~ |
|                   |
|    ~~~~~     ~~~~~|
|   ~~~~~~    ~~~~~~|
|G  # ~~        ~~  |
|                   |
|  G   K ~ P       ~|
|        ~~        ~|
|~~ ~~~~   ~~~~~~~  |
| ~ ~ ~ ~~ F~~ ~~~~~|
| ~ ~ ~ ~ ~ ~ ~ ~ ~ |
|                   |
|    ~~~~~     ~~~~~|
|   ~~~~~~    ~~~~~~|
|     ~~        ~~  |
---------------------
Player's coordinates: 17 20
Health = 10
Number of keys collected = 5
Number of keys remaining = 4

```

Hráč zadává příkazy, které zpracovává soubor `object_manager`, a tento soubor také konfiguruje prostředí hry na základě nastavení ze save souboru v `load_map`. V každém kroku aktivuje soubor `object_manager` metody v vektoru abstraktni tridy `creature`, ktera pak pomoci polymorfizmu pres jediny interface update zmenuje podtřídy , ktere jsou zodpovědne za AI(nepřátelé) a prostředí(ohen).

### Kde mám polymorfismus?

V `Game_start` používám polymorfismus - mam vector all_objects ktery je vector abstraktni tridy z virtualnimy metodamy. Pak z neji vychazi jeste dve abstraktni tridy living_Creature(player, enemy) a non_living_creature(fire, exit) - object object_manager muze pomoce tohoto vektoru pres univerzalni interface menit vsechne objekty. 