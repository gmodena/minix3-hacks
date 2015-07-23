204a205
> 	qnt \
858a860,863
> qnt:	qnt.c
> 	$(CCLD) -o $@ $?
> 	@install -S 4kw $@
> 
1061a1067
> 	/usr/bin/qnt \
1641,1642c1647,1651
< clean:
< 	rm -rf $(ALL) a.out core
---
> /usr/bin/qnt:	qnt
> 	install -lcs $? $@
> 
> clean:
> 	rm -rf $(ALL) a.out core
