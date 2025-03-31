PROJ=proj3
LATEX=pdflatex
BIBTEX=bibtex

$(PROJ).pdf: $(PROJ).tex
	$(LATEX) $(PROJ)
	$(BIBTEX) $(PROJ) || true
	$(LATEX) $(PROJ)
	$(LATEX) $(PROJ)

clean:
	rm -f $(PROJ).aux $(PROJ).log $(PROJ).out $(PROJ).toc \
		$(PROJ).lof $(PROJ).lot $(PROJ).bbl $(PROJ).blg
	# VS Code automated compilation files
	rm -f $(PROJ).fdb_latexmk $(PROJ).fls $(PROJ).synctex.gz

clean-all: clean
	rm -f $(PROJ).pdf

.PHONY: clean clean-all
