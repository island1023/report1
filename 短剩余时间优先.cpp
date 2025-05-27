#include<stdio.h>
#include<stdlib.h>
typedef struct PCB {
    int id;//�������
    int arrivetime;//���񵽴�ʱ��
    int runtime;//������Ҫִ�е�ʱ��
    int counttime;//��¼������һ��ʱ���,ʣ�µ���Ҫ�����ʱ��
    struct PCB* next;
}*task, pcb;
pcb* creattask(int x, int y, int z) {
    task newtask = (task)malloc(sizeof(pcb));
    newtask->id = x;
    newtask->arrivetime = y;
    newtask->runtime = z;
    newtask->counttime = z;
    newtask->next = NULL;
    return newtask;
}
void deltask(pcb* n, int x) {
    task d;
    if (n != NULL) {
        while (n->next->id != x) {
            n = n->next;
        }
        d = n->next;
        n->next = d->next;
        free(d);
    }
}
void count(pcb* n, int t) {  //q���ڼ�¼���ȵ��������λ�ã�p���ڱ�������
    pcb* q, * p;
    int qp=0; //���ڼ�¼��һ�������id��
    int temp = t; float time = 0; //time��¼��ǰʱ�䣬temp��¼�������,���ں�������
    float zt = 0, dt = 0;  //zt���ڼ�¼����תʱ��,dt��¼�ܴ�Ȩ��תʱ��
    while (t != 0) {
        p = n->next;
        q = p;
        while (p != NULL) { //�ҵ����ȵ��������
            if (p->arrivetime < q->arrivetime) {
                q = p;
            }
            p = p->next;
        }
        p = n->next;
        while (p != NULL) { //�ҵ����ھ����Ķ����������������̵�����
            if ((p->arrivetime <= time || p->arrivetime == q->arrivetime) && p->counttime < q->counttime)
                q = p;
            p = p->next;
        }
        q->counttime--;
        if(qp==0||qp!=q->id)
            printf("��ǰִ�е��������Ϊ %d \n", q->id);
        qp = q->id;
        if (time < q->arrivetime)//��ֹʱ����ͣ
            time = q->arrivetime;
        time++;
        if (q->counttime== 0) {
            printf("����%d����\n", q->id);
            printf("��������תʱ��Ϊ %.0f \n", time - q->arrivetime);
            zt = zt + time - q->arrivetime;
            printf("�������Ȩ��תʱ��Ϊ %.2f \n\n", (time - q->arrivetime) / q->runtime);
            dt = dt + (time - q->arrivetime) / q->runtime;
            deltask(n, q->id);
            --t;
        }
    }
    printf("\n");
    printf("ƽ����תʱ��Ϊ %.2f \n", zt / temp);
    printf("ƽ����Ȩ��תʱ��Ϊ %.2f \n", dt / temp);
}
int main() {
    int n, i, y, z;
    task tail = NULL;
    task head = NULL;
    printf("��������������:");
    scanf("%d", &n);
    tail = (task)malloc(sizeof(pcb));
    head = tail;
    for (i = 1; i <= n; i++) {
        printf("������%d������ĵ���ʱ�䡢����ʱ��:", i);
        scanf("%d%d", &y, &z);
        tail->next = creattask(i, y, z);
        tail = tail->next;
    }
    count(head, n);
}