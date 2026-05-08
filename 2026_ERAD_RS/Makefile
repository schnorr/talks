NAME=2026_Analise_Desempenho
all: $(NAME).pdf

%.tex: %.org
	emacs -batch -l ~/.emacs.d/init.el \
	   $^  --funcall org-babel-tangle
	emacs -batch -l ~/.emacs.d/init.el \
           --eval "(setq enable-local-eval t)" \
           --eval "(setq enable-local-variables t)" \
	   --eval "(setq org-export-babel-evaluate t)" \
	   $^  --funcall org-latex-export-to-latex

%.pdf: %.tex
	cp $(NAME).tex /tmp
	pdflatex -shell-escape $^
	bibtex `basename $^ .tex`
	pdflatex -shell-escape $^
	pdflatex -shell-escape $^
	pdflatex -shell-escape $^
# pdftops `basename $^ .tex`.pdf
# ps2pdf14 -dPDFSETTINGS=/prepress `basename $^ .tex`.ps


TGZ_NAME=cap3-erad26
TGZ_FILES=$(NAME).tex SBCbookchapter.cls sbc-template.sty sbc.bst refs.bib Makefile

tgz: $(NAME).tex
	rm -rf /tmp/$(TGZ_NAME) $(TGZ_NAME).tgz
	mkdir -p /tmp/$(TGZ_NAME)
	cp $(TGZ_FILES) /tmp/$(TGZ_NAME)/
	tar -czf $(TGZ_NAME).tgz -C /tmp $(TGZ_NAME)
	rm -rf /tmp/$(TGZ_NAME)
	@echo "Pacote criado: $(TGZ_NAME).tgz"

clean:
	rm -f $(NAME).aux $(NAME).bbl $(NAME).blg $(NAME).log $(NAME).out *~

distclean: clean
	rm -f $(NAME).html $(NAME).tex $(NAME).pdf $(TGZ_NAME).tgz
