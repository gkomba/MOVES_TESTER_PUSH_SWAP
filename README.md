AFTER RUN THE ./tester
OPEN 2 TABS O TERMINAL
COPY AND PASTE THIS COMANDS

client(TAB 1):
	rm tests.txt ; i=1 ; while [ $i -lt 18005 ] ; do ARG=("$(shuf -i 1-1000 -n 100)") ; ./push_swap $ARG | wc -l >> tests.txt ; clear ; i=$((i + 1)) ; echo $i ; done

server(TAB 2):
	while [ 1 ] ; do ./tester tests.txt ; sleep 0.5 ; clear ; done
