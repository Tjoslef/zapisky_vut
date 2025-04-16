PROJ=proj3
LATEX=latex
DVIPS=dvips
PS2PDF=ps2pdf

$(PROJ).pdf: $(PROJ).tex
	$(LATEX) $(PROJ)
	$(LATEX) $(PROJ)
	$(DVIPS) -sPAPERSIZE=a4 $(PROJ).dvi
	$(PS2PDF) $(PROJ).ps

clean:
	rm -f $(PROJ).aux $(PROJ).log $(PROJ).out $(PROJ).toc \
		$(PROJ).lof $(PROJ).lot $(PROJ).bbl $(PROJ).blg
	# VS Code automated compilation files
	rm -f $(PROJ).fdb_latexmk $(PROJ).fls $(PROJ).synctex.gz

clean-all: clean
	rm -f $(PROJ).pdf

.PHONY: clean clean-all
