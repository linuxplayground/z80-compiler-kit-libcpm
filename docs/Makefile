.PHONY: all clean

all:
	latexmk libcpm.tex
	pandoc -s libcpm.tex -o libcpm.md

clean:
	rm -f *.aux *.fdb_latexmk *.fls *.log *.out *.toc *.gz

