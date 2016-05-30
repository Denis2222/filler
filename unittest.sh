for f in ./resources/*.filler
do
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/toto.flr | tail -n 4
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/toto.flr | tail -n 4
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/toto.flr | tail -n 4
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/tata.flr | tail -n 4
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/tata.flr | tail -n 4
	./resources/filler_vm -q -p1 ./filler -p2 "$f" -f ./resources/tata.flr | tail -n 4
done
