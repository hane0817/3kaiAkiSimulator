#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_LINKS 2000

// ノードの構造体
typedef struct
{
    int id;
    double latitude;
    double longitude;
    int population;
} Node;

// リンクの構造体
typedef struct
{
    int node1;
    int node2;
    double distance;
    int capacity;
} Link;

// ノード情報を表示する関数
void printNode(Node node)
{
    printf("ノードID: %d %lf %lf %d\n", node.id, node.latitude, node.longitude, node.population);
}

// リンク情報を表示する関数
void printLink(Link link)
{
    printf("(%d, %d): %d %lf\n", link.node1, link.node2, link.capacity, link.distance);
}

int main()
{
    // ファイルポインタを用意してファイルを開く
    FILE *node_file = fopen("exam_s10_node.dat", "r");
    FILE *link_file = fopen("exam_s10_link.dat", "r");

    // ノードとリンクの配列を用意
    Node nodes[MAX_NODES];
    Link links[MAX_LINKS];

    // ノードとリンクの数を記録
    int num_nodes = 0;
    int num_links = 0;

    // 総人口
    int population = 0;

    // ファイルからノードデータを読み込む
    while (fscanf(node_file, "%d,%lf,%lf,%d", &nodes[num_nodes].id, &nodes[num_nodes].latitude, &nodes[num_nodes].longitude, &nodes[num_nodes].population) == 4)
    {
        population += nodes[num_nodes].population;
        num_nodes++;
    }

    // ファイルからリンクデータを読み込む
    while (fscanf(link_file, "%d,%d,%d", &links[num_links].capacity, &links[num_links].node1, &links[num_links].node2) == 3)
    {
        // ノード間の距離を計算
        double x_diff = (nodes[links[num_links].node2].latitude - nodes[links[num_links].node1].latitude) * 3600.0 / 300.0 * 10.0;
        double y_diff = (nodes[links[num_links].node2].longitude - nodes[links[num_links].node1].longitude) * 3600.0 / 450.0 * 10.0;
        links[num_links].distance = sqrt(pow(x_diff, 2.0) + pow(y_diff, 2.0));

        num_links++;
    }

    // ノード情報を出力
    printf("ノード情報:\n");
    for (int i = 0; i < num_nodes; i++)
    {
        printf("ノードID:%d 緯度：%.6lf 経度：%.6lf 人口比：%.6lf\n", nodes[i].id, nodes[i].latitude, nodes[i].longitude, (double)nodes[i].population / (double)population);
    }

    // リンク情報を出力
    printf("\nリンク情報:\n");
    for (int i = 0; i < num_links; i++)
    {
        printLink(links[i]);
    }

    // ファイルを閉じる
    fclose(node_file);
    fclose(link_file);

    return 0;
}
