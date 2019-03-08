void RFNrtc(const char *dirname=cwd, const char *ext=".root")
{ TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  if (files) { TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) { fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext)){
	cout<<fname.Data() << endl;
      }
    }
  }
}
