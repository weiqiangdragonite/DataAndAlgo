/*
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct node {
	int dev_num;
	int dev_type;
	char dev_name[256];
	int location;
	//char location_name[256];
	char time[256];
	char data[1024];
	void *dev;
	struct node *next;
};
/* 头指针 */
struct node *head = NULL;

struct temp_humi_dev {
	float temp;
	float humi;
	float max_temp;
	float min_temp;
	float max_humi;
	float min_humi;
};

struct ups_dev {
	float volt;
	float elec;
	float max_volt;
	float min_volt;
	float max_elec;
	float min_elec;
};

struct water_dev {
	int status;
};


int
main(int argc, char *argv[])
{
	struct node *ptr;
	ptr = malloc(sizeof(struct node));

	ptr->dev_num = 1;
	ptr->dev_type = 1;
	snprintf(ptr->dev_name, sizeof(ptr->dev_name), "温湿度1");
	ptr->location = 1;
	ptr->next = NULL;

	struct temp_humi_dev *t_ptr;
	t_ptr = malloc(sizeof(struct temp_humi_dev));

	t_ptr->temp = 28.0;
	t_ptr->humi = 28.0;

	ptr->dev = t_ptr;

	printf("t_ptr addr = %p, and point to %p\n", &t_ptr, t_ptr);
	printf("ptr->dev point to %p\n", ptr->dev);
	printf("dev_temp = %f\n", t_ptr->temp);
	printf("dev_num = %d, dev_name = %s, dev_temp = %f\n", ptr->dev_num,
		ptr->dev_name, ((struct temp_humi_dev *) ptr->dev)->temp);

	free(t_ptr);
	free(ptr);
	return 0;
}










