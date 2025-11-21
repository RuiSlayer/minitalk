/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:06:07 by rucosta           #+#    #+#             */
/*   Updated: 2025/04/07 16:35:40 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == ch)
		{
			return (ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}

/* void test_memchr(void *(*memchr_func)(const void *, int, size_t)) {
    unsigned char data[] = "Hello, World!";
    size_t data_len = sizeof(data) - 1;  // Exclude the null terminator
    
    // Test case 1: Character found in the middle of the string
    unsigned char *result = (unsigned char *)memchr_func(data, 'o', data_len);
    if (result != NULL && *result == 'o') {
        printf("Test 1 passed: Found 'o' in 'Hello, World!'\n");
    } else {
		printf("result 1: %s\n", result);
        printf("Test 1 failed\n");
    }

    // Test case 2: Character not found in the string
    result = (unsigned char *)memchr_func(data, 'z', data_len);
    if (result == NULL) {
        printf("Test 2 passed: 'z' not found in 'Hello, World!'\n");
    } else {
        printf("Test 2 failed\n");
    }

    // Test case 3: Character is at the beginning of the string
    result = (unsigned char *)memchr_func(data, 'H', data_len);
    if (result != NULL && *result == 'H') {
        printf("Test 3 passed: Found 'H' at the beginning\n");
		printf("result 3: %c\n", *result);
    } else {
        printf("Test 3 failed\n");
    }

    // Test case 4: Character is at the end of the string
    result = (unsigned char *)memchr_func(data, '!', data_len);
    if (result != NULL && *result == '!') {
        printf("Test 4 passed: Found '!' at the end\n");
    } else {
        printf("Test 4 failed\n");
    }

    // Test case 5: Multiple occurrences of a character ('l')
    result = (unsigned char *)memchr_func(data, 'l', data_len);
    if (result != NULL && *result == 'l') {
        printf("Test 5 passed: Found first 'l'\n");
    } else {
        printf("Test 5 failed\n");
    }

    // Test case 6: Empty string (edge case)
    result = (unsigned char *)memchr_func("", 'a', 0);
    if (result == NULL) {
        printf("Test 6 passed: Empty string returns NULL\n");
    } else {
        printf("Test 6 failed\n");
    }

    // Test case 7: Single byte string
    result = (unsigned char *)memchr_func("A", 'A', 1);
    if (result != NULL && *result == 'A') {
        printf("Test 7 passed: Found 'A' in single byte string\n");
    } else {
        printf("Test 7 failed\n");
    }

    // Test case 8: Large memory block
    unsigned char large_data[1000];
    memset(large_data, 'x', sizeof(large_data));  // Fill with 'x'
    result = (unsigned char *)memchr_func(large_data, 'y', sizeof(large_data));
    if (result == NULL) {
        printf("Test 8 passed: 'y' not found in large block\n");
    } else {
        printf("Test 8 failed\n");
    }
}

int main() {
    // Call the test function with the implemented memchr function
    test_memchr(memchr);
    return 0;
} */