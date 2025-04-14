[ORG 0x00] ; 코드의 시작 어드레스를 0x00으로 설정
[BITS 16] ; 이하의 코드는 16비트 코드로 설정

SECTION .text ; text 섹션(세그먼트)를 정의

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 코드 영역
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
START:
    mov ax 0x1000 ; 보호 모드 엔트리 포인트의 시작 어드레스를
                  ; 세그먼트 레지스터 값으로 변환
    mov ds, ax    ; DS 세그먼트 레지스터에 설정
    mov es, ax    ; ES 세그먼트 레지스터에 설정

    cli           ; 인터럽트가 발생하지 못하도록 설정
