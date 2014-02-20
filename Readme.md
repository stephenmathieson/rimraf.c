
# rimraf

  rm -rf

[![Build Status](https://travis-ci.org/stephenmathieson/rimraf.c.png?branch=master)](https://travis-ci.org/stephenmathieson/rimraf.c)

## Installation

  Install with [clib(1)](https://github.com/clibs/clib):

    $ clib install stephenmathieson/rimraf.c

## API

### `int rimraf(char *path)`

  `rm -rf path`, returning 0 on success and -1 on failure

## CLI

  For extra fun, `rimraf(1)` can be built and installed:

    $ git clone https://github.com/stephenmathieson/rimraf.c /tmp/rimraf
    $ cd /tmp/rimraf
    $ make install

  Once installed, `rimraf(1)` allows for:

    $ rimraf /tmp/rimraf
    $ rimraf a b c d /foo/bar
    $ sudo rimraf / # just kidding

## License

(The MIT License)

Copyright (c) 2013 Stephen Mathieson &lt;me@stephenmathieson.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.