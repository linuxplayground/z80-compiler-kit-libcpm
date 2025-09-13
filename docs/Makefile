.PHONY: all clean

all:
	latexmk cpmlib.tex
	pandoc -s cpmlib.tex -o cpmlib.md

clean:
	rm -f *.aux *.fdb_latexmk *.fls *.log *.out *.toc *.gz

