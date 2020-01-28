#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca_bin (int ini, int end, int val, int v[]) {
	if (ini == end) {
		return ini;
	}
	
	int meio = (ini + end) / 2;
	
	if (v[meio] < val) return busca_bin(meio + 1, end, val, v);
	else if (v[meio] == val) return busca_bin(ini, meio , val, v);
	else return busca_bin(ini, meio - 1, val, v);
}

int main () {
	
	int n = 0;
	int k = 0;
	
	FILE * fp;
	fp = freopen("input2.txt", "r", stdin);
	
	if (fp != NULL) {
		char buf[10];
		fgets(buf, 10, fp);
		n = strtol(buf, NULL, 10);
		
		int casas[n];
		int i = 0;
		
		fgets(buf, 10, fp);
		for (i = 0; i < n; i++) {
			fgets(buf, 10, fp);
			casas[i] = strtol(buf, NULL, 10);
		}
		
		fgets(buf, 10, fp);
		k = strtol(buf, NULL, 10);
		
		int y = 0;
		for (i = 0; i < n -1 ; i++) {
			y = busca_bin(i + 1, n - 1, k - casas[i], casas);
			if (casas[i] + casas[y] == k) {
				printf("%d %d\n", casas[i], casas[y]);
				break;
			}
		}
	}	
	
	return (0);
}
