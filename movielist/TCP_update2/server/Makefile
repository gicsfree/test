objs = tcp_server.o wrap.o 
tcp_server: $(objs)
	$(CC) $^ -o $@

sources = tcp_server.c wrap.c

include $(sources:.c=.d)

%.d:%.c
	set -e;rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\o[ :]*,\1.o $@ :,g' < $@.$$$$ >$@; \
	rm -f $@.$$$$

clean:
	@echo "cleanning project"
	-rm *.o *.d
	@echo "clean completed"

.PHONY: clean
