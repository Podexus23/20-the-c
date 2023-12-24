

int getLength(int arr[], int maxsize);

int main(int arr[], int maxsize)
{
  return getLength(arr, maxsize);
}

int getLength(int arr[], int maxsize)
{
  int counter;
  counter = 0;
  for (int i = 0; i < maxsize; ++i)
  {
    if (arr[i] != '\0')
      ++counter;
    else
      --i;
  }
  return counter;
}