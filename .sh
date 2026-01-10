#!/usr/bin/env bash
set -euo pipefail
flag() {
	for f in "$@"
		do [[ -e ".flags/$f" ]] || return 1
	done
}
mkdir -p logs bin
ARGS=(
	-I/usr/include
	-lsfml-graphics
	-lsfml-window
	-lsfml-system
)
g++ *.cpp -o bin/game ${ARGS[@]} &> logs/main.log
find -empty -delete
./bin/game