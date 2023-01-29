import argparse
import os

DATABASE = {
    'Kasaneru': 'Adamov',
    'YuraDudar': 'Dudar',
    'vivichv9': 'Efimenko',
    'hedgefo9': 'Fedorov',
    'Aflipov': 'Filippov',
    'Haliava': 'Fomin',
    'Destroyer888': 'Gigolaev',
    'Mgorohov': 'Gorohov',
    'tng00': 'Huan',
    'BaronPipistron': 'Kontsebalov',
    'MeDGranD': 'Lyubovarsky',
    'shpashka': 'Malko',
    'Vavarr': 'Moravskaya',
    'Nikita14ZSP': 'Mozgovoy',
    'Dots109': 'Nedosekin',
    'Egori11a': 'Potapov',
    'Er4s3r1': 'Potexin',
    'ssanchellaa': 'Serakova',
    'box1t': 'Seruy',
    'willr4in': 'Shambilov',
    'Alexstepano': 'Stepanov',
    'ktuzova': 'Tuzova',
    'Nyamerka': 'Voropaev',
    'zibushka': 'Yashin',
    'President-OrackBobama': 'Yusufov'
}


def get_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", "--name", dest="github_name",
                        help="Github's username")
    (options, arguments) = parser.parse_args()
    return options


option = get_arguments()
os.chdir(DATABASE.get(option.github_name, '.'))