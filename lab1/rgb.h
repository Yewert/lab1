#pragma once

class RGB
{
	public:
		RGB()
		{
			colors = new int[3];
      colors[0]=0;
      colors[1]=0;
      colors[2]=0;
		}

    int* colors;
};
