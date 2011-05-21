objs = main.o ./bit/d2b.o ./bit/multi.o ./bit/encryption.o ./bit/exchange.o 
main: $(objs)
	$(CC) $^ -o $@

sources = main.c ./bit/d2b.c ./bit/multi.c ./bit/encryption.c ./bit/exchange.c

include $(sources:.c=.d)

%.d:%.c
	set -e;rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\o[ :]*,\1.o $@ :,g' < $@.$$$$ >$@; \
	rm -f $@.$$$$

clean:
	@echo "cleanning project"
	-rm main *.o *.d
	@echo "clean completed"

.PHONY: clean
