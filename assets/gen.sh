#!/bin/bash
if [ -z $1 ]; then
    file="$(ls .. | grep hartings | head -n 1 | cut -d '.' -f 1,2,3)"
else
  file=$1
fi

pandoc -f markdown -t html -o ../$file.pdf.html -M pagetitle=pt -s -N --number-offset=0 --template=hdoc.tpl -H hdoc_pdf.css.inc -H  hdoc_syntax.css.inc --highlight-style pygments ../$file.md
prince ../$file.pdf.html -o ../$file.pdf