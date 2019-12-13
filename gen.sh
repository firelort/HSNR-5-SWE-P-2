#!/bin/bash
pandoc -f markdown -t html -o $1.pdf.html -M pagetitle=pt -s -N --number-offset=0 --template=hdoc.tpl -H hdoc_pdf.css.inc -H  hdoc_syntax.css.inc --highlight-style pygments $1.md
/Applications/bin/prince $1.pdf.html -o $1.pdf