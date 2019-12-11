<style type="text/css">
/* hdoc_pdf.css */

@page {
   size: A4 portrait;
   margin-top: 2.5cm;
   margin-left: 1.5cm;
   margin-right: 1.5cm;
   margin-bottom: 2cm;
   padding: 0cm;

  @top-left {
    content: flow(tl-content-flow);
    vertical-align: bottom;
    margin-bottom: 0.5cm;
    padding-bottom:0.1cm;
    font-family: "Roboto Condensed", sans-serif;
    border-bottom:1px solid gray;
  }

  @top-center {
    content: flow(tm-content-flow);
    vertical-align: bottom;
    margin-bottom: 0.5cm;
    padding-bottom:0.1cm;
    font-family: "Roboto Condensed", sans-serif;
    border-bottom:1px solid gray;
  }

  @top-right {
    content: flow(tr-content-flow);
    font-size:8pt; /*1em;*/
    text-align:right;
    vertical-align: bottom;
    margin-bottom: 0.5cm;
    padding-bottom:0.1cm;
    font-family: "Roboto Condensed", sans-serif;
    border-bottom:1px solid gray;
  }

  @bottom-center {
    font-size:8pt; /*1em;*/
    text-align:center;
    vertical-align: top;
    margin-top: 0.5cm;
    padding-top:0.1cm;
    font-family: "Roboto Condensed", sans-serif;
  }
}
.tl-content {
    flow: static(tl-content-flow);
    width:5cm;
    font-size:8pt; /*1em;*/
    text-align:left;
}

.tm-content {
    flow: static(tm-content-flow);
    width:8cm;
    font-size:10pt;
    text-align:center;
}

.tr-content {
   /*display: none;*/
   flow: static(tr-content-flow);
   width:5cm;
   font-size:8pt; /*1em;*/
   text-align:right;
}

.tr-page {
   content: "Seite " counter(page) " von " counter(pages);
}
body {
   font-family: "Roboto", "Roboto Condensed", sans-serif;
   font-size:10pt; /*1em;*/
}

code {
   font-family: "LettrGoth12 BT", monospace;
   font-size:1em;
}

h1, h2, h3, h4, h5, h6 {
   font-family: "Roboto Condensed", sans-serif;
   page-break-after: avoid;
}

h1 {
   page-break-before: auto;
}

h1.clDocPartHeader {
   padding-bottom: 5px;
   border-bottom: 2px solid;
}

h1.clDocPartHeader {
   page-break-before: always;
}

h1.clDocPartHeader:first-of-type {
   page-break-before: avoid;
}

h1.clDocPartHeader + h1 {
   page-break-before: avoid;
}

figure {
   margin-left: auto;
   margin-right: auto;
   text-align: center;
}

figure img {
   width: 15cm;
}

table {
   border: 1px solid #AAAAAA;
   border-collapse: collapse;
   caption-side: bottom;
   margin-left: auto;
   margin-right: auto;
}

caption {
   margin-top: 0.1cm;
}

th, td {
   padding: 0.2cm;
   border: 1px solid #AAAAAA;
}

p {
   text-align: justify;
   -moz-hyphens: auto;
   -o-hyphens: auto;
   -webkit-hyphens: auto;
   -ms-hyphens: auto;
   hyphens: auto;    
   hyphenate-limit-chars: auto 3;
   hyphenate-limit-lines: 2;    
   prince-hyphenate-before: 3;
   prince-hyphenate-after: 3;
   prince-hyphenate-lines: 2;    
}

p + ul {
  margin-top: -10px;
}

td.lineNumbers {
  width: 5%;
}

ul {
   margin-left: 0;
   padding-left: 1.5em;
}

ol {
   margin-left: 0;
   padding-left: 2em;
}

blockquote {
   margin-left: 0;
   padding-left: 1.5em;
}

/* EOF */
</style>