
XELATEX_FLAGS = -halt-on-error -file-line-error
XELATEX = xelatex
TEXSRC = '\def\asnver{@VERSION@}\input{asn1c-usage}'
NEWTEXSRC = '\def\asnver{@VERSION@}\input{asn1c-usage-new}'

regen:
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(TEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(TEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) $(TEXSRC)

newregen:
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(NEWTEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(NEWTEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) $(NEWTEXSRC)

EXTRA_DIST = $(srcdir)/*.tex

CLEANFILES = *.*~ *.aux *.dvi *.log *.out *.toc
