# IJC Tryharding Remastered Demo

- Pro zatím jsou v tomto repozitáři pouze testové kódy, které vracejí buď int, char, string mají nedefinované chování nebo nejdou přeložit.
- `./main.sh` se pokusí nainstalovat [bat](https://github.com/sharkdp/bat), což je náhrada za `cat` s barvami a čísly řádků. Kdyby to nefungovalo, tak to nainstalujte zvlášť nebo v `main.sh` nahraďte `batcat` za `bat`, pokud jste na jiným linuxu jak na ubuntu/debianu, popřípadě pokud vůbec nechcete barvičky, tak jenom za `cat`.

## První spuštění
- `chmod +x main.sh`
- `./main.sh`

### Plány do budoucna
- [x] basic kódy
- [x] sizeof kódy
- [x] modulární kódy
- [x] static kódy
- [ ] deklarace funkcí/ukazatelů
- [ ] revision mód pro všechny kódy nad tímto bodem (komentáře, shuffle úloh, atd.)
- [ ] prostředí pro makra
- [ ] prostředí pro složité kódy
- [ ] testy pro makra a složité kódy
