/*
 * 3.2.7 example: 一元多项式相加、相乘
 */


/*
 * 用数组实现
 */
struct node {
	int coeff_array[MAX_DEGREE + 1];	/* 系数 */
	int high_power;
};

typedef struct node polynomial_t;


void
zero_polynomial(polynomial_t *poly)
{
	int i;
	for (i = 0; i < MAX_DEGREE; ++i)
		poly->coeff_array[i] = 0;
	poly->high_power = 0;
}

/*
 * 多项式相加
 */
void
add_polynomial(const polynomial_t *poly1, const polynomial_t *poly2,
		polynomial_t *poly_sum)
{
	int i;

	zero_polynomial(poly_sum);
	poly_sum->high_power = max(poly1->high_power, poly2->high_power);

	for (i = poly_sum->high_power; i >= 0; --i)
		poly_sum->coeff_array[i] = poly1->coeff_array[i] + poly2->coeff_array[i];
}

/*
 * 多项式相乘
 */
void
mul_polynomial(const polynomial_t *poly1, const polynomial_t *poly2,
		polynomial_t *poly_prod)
{
	int i, j;

	zero_polynomial(poly_prod);
	poly_prod->high_power = poly1->high_power + ploy2->high_power;

	if (poly_prod->high_power > MAX_DEGREE)
		error("exceeded array size");

	for (i = 0; i <= poly1->high_power; ++i) {
		for (j = 0; j <= poly1->high_power; ++j)
			poly_prod->coeff_array[i + j] += poly1->coeff_array[i] * poly2->coeff_array[j];
	}
}



/*
 * 用链表实现
 */
struct node {
	int coefficient;
	int exponent;
	struct node *next;
};



/*
 * find
 */

/*
 *
 */
void
delete(polynomial_t *list)
{
	polynomial_t *ptr;
	polynomial_t *tmp;

	ptr = list->next;	/* with header */
	while (ptr) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	list->next = NULL;
}


/*
 * insert: from largest to least order
 * 同类项的自动合并
 */
void
insert(polynomial_t *list, int coeff, int exp)
{
	polynomial_t *ptr = NULL;
	polynomial_t *lp, *prev;

	/* have header, point to the first */
	lp = list->next;
	prev = list;

	ptr = malloc(sizeof(polynomial_t));
	ptr->coefficient = coeff;
	ptr->exponent = exp;
	ptr->next = NULL;

	/* insert in middle */
	while (lp) {
		if (exp > lp->exponent) {
			ptr->next = prev->next;
			prev->next = ptr;
			break;
		} else if (exp == lp->exponent) {
			lp->coefficient += ptr->coefficient;
			free(ptr);
			break;
		}
		lp = lp->next;
		prev = prev->next;
	}

	/* insert after header or insert at tail */
	if (lp == NULL) {
		prev->next = ptr;
	}
}


/*
 * add
 */
void
add(polynomial_t *poly1, polynomial_t *poly2, polynomial_t *poly3)
{
	polynomial_t *ptr;
	polynomial_t *list1, *list2, *list3;

	delete(poly3);

	list1 = poly1->next;
	list2 = poly2->next;
	list3 = poly3;	/* point to header */

	/* method 1: first copy list1 to list3, and then insert list2 to list3
	 * to do the add */

	/* method 2: copy the list1 and list2 to list3 at the same time and do
	 * the add */
	while (list1 && list2) {
		if (list1->exponent > list2->exponent) {
			exp = list1->exponent;
			coeff = list1->coefficient;

			list1 = list1->next;
		} else if (list1->exponent < list2->exponent) {
			exp = list2->exponent;
			coeff = list2->coefficient;

			list2 = list2->next;
		} else {
			exp = list1->exponent;
			coeff = list1->coefficient + list2->coefficient;

			list1 = list1->next;
			list2 = list2->next;
		}

		ptr = malloc(sizeof(polynomial_t));
		ptr->coefficient = coeff;
		ptr->exponent = exp;
		ptr->next = NULL;

		list3->next = ptr;
		list3 = list3->next;
	}

	/* list1 still has items */
	while (list1) {
		ptr = malloc(sizeof(polynomial_t));
		ptr->coefficient = list1->coefficient;
		ptr->exponent = list1->exponent;
		ptr->next = NULL;

		list3->next = ptr;
		list3 = list3->next;

		list1 = list1->next;
	}

	/* list2 still has items */
	while (list2) {
		ptr = malloc(sizeof(polynomial_t));
		ptr->coefficient = list2->coefficient;
		ptr->exponent = list2->exponent;
		ptr->next = NULL;

		list3->next = ptr;
		list3 = list3->next;

		list2 = list2->next;
	}
}


void
mul(polynomial_t *poly1, polynomial_t *poly2, polynomial_t *poly3)
{
	polynomial_t *ptr;
	polynomial_t *list1, *list2, *list3;

	delete(poly3);

	list1 = poly1->next;
	list2 = poly2->next;
	list3 = poly3;	/* point to header */

	while (list1) {
		list2 = poly2->next;
		while (list2) {
			//ptr = malloc(sizeof(polynomial_t));
			/* 系数相乘，指数相加 */
			//ptr->coefficient = list1->coefficient * list2->coefficient;
			//ptr->exponent = list1->exponent + list2->exponent;
			//ptr->next = NULL;

			//list3->next = ptr;
			//list3 = list3->next;

			/* 直接insert就不需要上面的步骤了 */
			insert(poly, list1->coefficient * list2->coefficient, list1->exponent + list2->exponent);

			list2 = list2->next;
		}
		list1 = list1->next;
	}
}


