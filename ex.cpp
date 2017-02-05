	//remove the first element of the vector - that elements represents the number of points
	coordinates.erase(coordinates.begin());

	int j = 2;
	for (int i = 0; i < coordinates.size(); i+=2)
	{
		//float x_temp = coordinates[i];
		int y = i+1;
		int y_next = j+1;
		//float y_temp = coordinates[y];

		//check other points
		for (; j < coordinates.size(); j+=2)
		{
			float dx = coordinates[j] - coordinates[i];
			float dy = coordinates[y_next] - coordinates[y];
			float slope = dy/dx;
			slopeVector.push_back(slope);
		}

		findDuplicates(slopeVector);

	}

	for (int i = 0; i < coordinates.size(); i++)
	{
		cout << slopeVector[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < coordinates.size(); i++)
	{
		cout << coordinates[i] << " ";
	}

	cout << endl;