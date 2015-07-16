#include "rbtree_augmented.h"
#include "stdio.h"
#include "stdlib.h"



struct hb_data {
	int key;
	int value;
	struct rb_node rb;
};

struct rb_root hb_root = RB_ROOT;

void hb_insert(struct hb_data *data, struct rb_root *root)
{
	struct rb_node **new = &root->rb_node, *parent = NULL;
	int key = data->key;

	while (*new) {
		parent = *new;
		if (key < rb_entry(parent, struct hb_data, rb)->key)
			new = &parent->rb_left;
		else
			new = &parent->rb_right;
	}

	rb_link_node(&data->rb, parent, new);
	rb_insert_color(&data->rb, root);
}

void print_tree(struct rb_node *node)
{
	struct hb_data *data;

	if (!node)
		return;

	data = rb_entry(node, struct hb_data, rb);
	if (node->__rb_parent_color & 1)
		printf("(%d) ", data->key);
	else
		printf("%d ", data->key);
	print_tree(node->rb_left);
	print_tree(node->rb_right);
}

void main(void)
{
	int a[] = {9, 5, 2, 7}, i;
	struct hb_data *data;

	for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		data = (struct hb_data *)malloc(sizeof(struct hb_data));
		data->key = a[i];
		hb_insert(data, &hb_root);
	}

	print_tree(hb_root.rb_node);
	printf("\n");
}
