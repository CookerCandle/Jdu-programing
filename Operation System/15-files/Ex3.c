#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 作成するダミーのファイル名
#define FILE_NAME "FileTest.txt"
// ダミーファイルの最大サイズ[byte]
#define MAX_FILE_SIZE 10000

//////////////////////////////
/// メイン関数
//////////////////////////////
int main(void) 
{
    // ディスク情報
    DWORD clusterSize, sectorSize;
    // ファイルポインタ
    FILE *fp;
    // ダミーファイルのサイズ[byte]
    int fileSize;

    // ディスク情報の取得・表示    
    GetDiskFreeSpace(NULL, &clusterSize, &sectorSize,	NULL, NULL);
	printf("Sector size  [byte] : %u\n", sectorSize);
    printf("Sectors per cluster : %u\n", clusterSize);
    printf("Cluster size [byte] : %u (%u[KB])\n", 
        clusterSize * sectorSize,
        clusterSize * sectorSize / 1024);

    // 生成するダミーファイルのサイズ入力
    printf("Enter byte to create file (1 to %d) : ", MAX_FILE_SIZE);    
    scanf("%d", &fileSize);
    // 最大容量を超える場合は異常終了
    if(fileSize > MAX_FILE_SIZE)
    {
        printf("Maximum file size (%d) exceeded.\n", MAX_FILE_SIZE);
        return 1;
    }

    // ダミーファイルを開く
    printf("Writing to the file \"%s\" (%d bytes)...", FILE_NAME, fileSize);
    fp = fopen(FILE_NAME, "wb");    
    // 1byteずつダミーの文字'A'を書き込み
    for (int i = 0; i < fileSize; i++) fputc('A', fp);
    // ダミーファイルを閉じる    
    fclose(fp);

    // ファイルプロパティの確認を指示
    printf("Done.\nCompare 'Size' vs 'Size on disk' in file properties.\n"); 
    
    return 0;
}