/*
 * Source1 : http://en.wikipedia.org/wiki/Fermat's_theorem_on_sums_of_two_squares
 * Source2 : http://en.wikipedia.org/wiki/Modular_arithmetic
 * Fermat's theorem on sum of two squres
 *  n <=> 1 (mod 4)
 *  n is an odd - prime
 *
 *	Source3 : http://www.math.hmc.edu/funfacts/ffiles/20008.5.shtml
 *
 * */
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long int ll;
/*main()
  {
  int T;
  scanf("%d", &T);
  while(T--)
  {
  bool ans = true;
  ll num;
  scanf("%lld", &num);
  for(ll i = 2; i * i <= num; ++i)
  {
  int cnt = 0;
  while(num % i == 0)
  {
  cnt ++;
  num /= i;
  }
  if(i % 4 == 3 && cnt % 2 == 1)
  {
  ans = false;
  break;
  }
  }
  if(num % 4 == 3) ans = false;
  if(ans) printf("Yes\n");
  else printf("No\n");
  }
  }
  */

#define MAX 1000000
bool isprime[MAX + 1];
ll primes[78498];
main()
{
	memset(isprime, 0xff, sizeof isprime);

	isprime[0] = isprime[1] = false;
	for(ll i = 2; i <= MAX; ++i)
		if(isprime[i])
			for(ll j = i * 2; j <= MAX; j += i)
				isprime[j] = false;

	ll cnt = 0;
	for(ll i = 0; i <= MAX; ++i)
		if(isprime[i])
			primes[cnt ++] = i;
	for(int i = 0; i < cnt; ++i)
		printf("%lld\n", primes[i]);
	int T;
	T = 0;
	scanf("%d", &T);
	while(T--)
	{
		ll num;
		scanf("%lld", &num);
		bool good = true;
		for(ll i = 0; i < cnt && good && ( primes[i] * primes[i] <= num ); ++i)
		{
			int ec = 0;
			while(num % primes[i] == 0)
			{
				ec ++;
				num /= primes[i];
			}
			if(primes[i] % 4 == 3 && ec % 2 == 1) good = false;
		}
		if(num % 4 == 3) good = false;
		if(!good) printf("No\n");
		else printf("Yes\n");
	}
}
