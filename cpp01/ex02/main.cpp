

int main(void)
{


	for (int i = 0; i < N_ZOMBS; i++)
	{
		zombs[i].anounce();
	}

	delete[] zombs;
	return 0;
}
