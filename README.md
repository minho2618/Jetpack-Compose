# 64bits-Multicore-OS
64비트 멀티코어 OS의 원리와 구조를 읽으며 실습한 내용임

## qemu 세팅
WSL: https://www.youtube.com/watch?v=zAI-OWkavAw&ab_channel=TechyCricketer
해당 영상보고 git clone 제외한 나머지 부분만 할 것

## qemu 실행
qemu-system-x86_64 -L . -m 64 -fda ./Disk.img -M pc

## c 파일을 컴파일하여 어셈블리어 파일 생성하기
gcc -c a.c -o a.o -02
