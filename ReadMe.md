# Omi C++ Parquet Wide Record Writers

[![Omi](https://github.com/Open-Markets-Initiative/Directory/blob/main/About/Images/Logo.png)](https://github.com/Open-Markets-Initiative/Directory)

Omi C++ Parquet wide record writers convert binary exchange protocol pcap data into [Apache Parquet](https://parquet.apache.org) columnar format using [Apache Arrow](https://arrow.apache.org).

Each protocol generates a single wide parquet record with all message fields as optional columns.

## Protocols

| Organization | Protocol |
| --- | --- |
| Chicago Mercantile Exchange | Simple Binary Encoding 1.8 |
| National Association of Securities Dealers Automated Quotations | Itch 5.0 |
| Investors Exchange | Investors Exchange Transport Protocol 1.6.6 |
| Securities Industry Automation Corporation | Opra Binary Interface 6.2 |
| European New Exchange Technology | Simple Binary Encoding 5.25 |

## Build

Requirements: C++23, CMake 3.28+, Apache Arrow, Boost (program_options)

```bash
mkdir build && cd build
cmake ..
make
```

## Usage

```bash
./<target> --input <pcap file> --output <parquet file>
```

Run with `--help` for all options including compression, row group size, and file size limits.

## Development

This entire repository is source generated. If you wish to suggest updates, the recommended process is to create an issue with changes and explanation. Time permitting, we will update the models and regenerate.

## Open Markets Initiative

The [Open Markets Initiative (Omi)](https://github.com/Open-Markets-Initiative/Directory) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods.

For a list of Omi projects: [Omi Directory](https://github.com/Open-Markets-Initiative/Directory/tree/main/Projects)

## Disclaimer

Any similarities between existing people, places and/or protocols is purely incidental.

Enjoy.
