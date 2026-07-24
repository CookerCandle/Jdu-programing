#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 作成するダミーのファイル名
#define FILE_NAME "DummyData.bin"
// ダミーファイルの最大サイズ[MB]
#define MAX_FILE_SIZE 1000

// 最小のメモリ確保単位(1MB)
#define MB (1024 * 1024)

//////////////////////////////
/// メイン関数
//////////////////////////////
int main(void) 
{
    // 開始時間計測用変数
    clock_t start;
    // ファイルポインタ
    FILE *fp;
    // ダミーファイルのサイズ[MB]
    int fileSize;
    
    // 書き込みデータのテンプレート（1MBの'A'埋め）
    char buffer[MB] = {'A'};

    // 生成するダミーファイルのサイズ入力
    printf("Enter MB to create file (1 to %d) : ", MAX_FILE_SIZE);    
    scanf("%d", &fileSize);
    // 最大容量を超える場合は異常終了
    if(fileSize > MAX_FILE_SIZE)
    {
        printf("Maximum file size (%d [MB]) exceeded.\n", MAX_FILE_SIZE);
        return 1;
    }

    // ダミーファイルを開く
    printf("Writing to disk...\n");
    fp = fopen(FILE_NAME, "wb");    
    // 1MBずつテンプレートデータを書き込み
    for (int i = 0; i < fileSize; i++) 
    {
        // ファイルポインタの先にテンプレートデータを書き込み
        fwrite(buffer, 1, MB, fp);
    }
    // ダミーファイルを閉じる    
    fclose(fp);
    
    // ダミーファイルの読み込みを3回繰り返し   
    for (int i = 1; i <= 3; i++) 
    {
        // 読み込み元を表示
        if (i == 1) printf("Read %d (from disk )... ", i);
        else        printf("Read %d (from cache)... ", i);

        // 時間計測開始
        start = clock();        
        // ファイルをバイナリ読み込みモードで開く
        fp = fopen(FILE_NAME, "rb");
        // 読み込み容量が0になるまで読み込み
        while (fread(buffer, 1, MB, fp) > 0);
        // ファイルを閉じる
        fclose(fp);  // ファイルを閉じる
        // 読み込み時間を表示
        printf("%.3lf sec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    }
    
    return 0;
}