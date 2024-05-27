#include <stdio.h>

#define ERROR -1

int main(int argc, char *argv[]) {
    int iTotalSectorCount = 1024;
    int iSectorNumber = 2;
    int iHeadNumber = 0;
    int iTrackNumber = 0;

    // 실제 이미지를 복사할 어드레스(물리 주소)
    char *pcTargetAddress = (char *)0x100000;

    while (1) {
        // 전체 섹터 수를 하나씩 감소시키면서 0이 될 때까지 섹터를 복사
        if (iTotalSectorCount == 0) {
            break;
        }
        iTotalSectorCount = iTotalSectorCount - 1;

        // 1 섹터를 읽어들여서 메모리 어드레스에 복사
        if (BIOSReadOneSector(iSectorNumber, iHeadNumber, iTrackNumber,
                              pcTargetAddress) == ERROR) {
            HandleDiskError();
        }

        // 1 섹터는 512(0x200) 바이트이므로, 복사한 섹터 수만큼 어드레스 증가
        pcTargetAddress = pcTargetAddress + 0x200;

        // 섹터 -> 헤드 -> 트랙 순으로 번호 증가
        iSectorNumber = iSectorNumber + 1;
        if (iSectorNumber < 19) {
            continue;
        }

        iTrackNumber = iTrackNumber + 1;
    }

    return 0;
}

// 발생한 에러를 처리하는 함수
void HandleDiskError() {
    printf("DISK Error~!!");
    while (1)
        ;
}
