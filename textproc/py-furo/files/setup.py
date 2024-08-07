#!/usr/bin/env python
# setup.py generated by flit for tools that don't yet use PEP 517

from distutils.core import setup

packages = \
['furo']

package_data = \
{'': ['*'],
 'furo': ['assets/*',
          'assets/scripts/*',
          'assets/styles/*',
          'assets/styles/base/*',
          'assets/styles/components/*',
          'assets/styles/content/*',
          'assets/styles/extensions/*',
          'assets/styles/variables/*',
          'theme/*',
          'theme/furo/*',
          'theme/furo/components/*',
          'theme/furo/partials/*',
          'theme/furo/sidebar/*',
          'theme/furo/static/*']}

package_dir = \
{'': 'src'}

install_requires = \
['beautifulsoup4', 'sphinx >= 5.0,<8.0', 'sphinx-basic-ng >= 1.0.0.beta2', 'pygments >= 2.7']

entry_points = \
{'sphinx.html_themes': ['furo = furo']}

setup(name='furo',
      version='%%PORTVERSION%%',
      description='A clean customisable Sphinx documentation theme.',
      author=None,
      author_email='Pradyun Gedam <mail@pradyunsg.me>',
      classifiers=[
          'Framework :: Sphinx',
          'Framework :: Sphinx :: Theme',
          'Development Status :: 5 - Production/Stable',
          'License :: OSI Approved :: MIT License',
          'Environment :: Web Environment',
          'Intended Audience :: Developers',
          'Programming Language :: Python :: 3',
          'Programming Language :: Python :: 3.8',
          'Programming Language :: Python :: 3.9',
          'Programming Language :: Python :: 3.10',
          'Programming Language :: Python :: 3.11',
          'Programming Language :: Python :: 3.12',
          'Operating System :: OS Independent',
          'Topic :: Documentation',
          'Topic :: Software Development :: Documentation',
      ],
      url=None,
      packages=packages,
      package_data=package_data,
      package_dir=package_dir,
      install_requires=install_requires,
      entry_points=entry_points,
      python_requires='>=3.8',
     )
