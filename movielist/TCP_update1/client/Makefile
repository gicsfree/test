objs = tcp_client.o wrap.o analysis.o
tcp_client: $(objs)
	$(CC) $^ -o $@

sources = tcp_client.c wrap.c analysis.c

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
