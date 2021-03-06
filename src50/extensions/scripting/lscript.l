public singleton lscript
{
    eval(string script)
        = lscriptEngine.buildScript(script).compiled();
            
    evalPath(string path)
        = lscriptEngine.buildScriptFile(path).compiled();
        
    load(string path)
        = lscriptEngine.loadPath(path);
        
    interpret(string script)
    {
        var full_script := "program=" + script + ";";
        
        var ns := self.eval(full_script);
    
        var s := ns.program;
                            
        if (script[0]==$123) {
            ^ s
        }                            
        else
        {
            ^ s();
        }                    
    }        
}