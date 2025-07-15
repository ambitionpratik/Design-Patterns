#include <iostream>

class DataExporter {
public:
    void Export() {
        LoadData();
        FormatData();
        SaveFile();
    }

protected:
    virtual void LoadData() = 0;
    virtual void FormatData() = 0;

    void SaveFile() {
        std::cout << "Saving file to disk.\n";
    }
};

class CSVExporter : public DataExporter {
protected:
    void LoadData() override {
        std::cout << "Loading data for CSV export.\n";
    }

    void FormatData() override {
        std::cout << "Formatting data as CSV.\n";
    }
};

class JSONExporter : public DataExporter {
protected:
    void LoadData() override {
        std::cout << "Loading data for JSON export.\n";
    }

    void FormatData() override {
        std::cout << "Formatting data as JSON.\n";
    }
};

int main() {
    DataExporter* exporter = new CSVExporter();
    exporter->Export();
    delete exporter;

    exporter = new JSONExporter();
    exporter->Export();
    delete exporter;

    return 0;
}
