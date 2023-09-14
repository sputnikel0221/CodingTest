if (c != map[cx][cy] && map[cx][cy] > 0)
                {
                    result = min(result, length);
                    cout << "\n"
                         << c << " : " << map[cx][cy] << "\n" 
                         << cx << " : " << cy << " = " << length;

                }