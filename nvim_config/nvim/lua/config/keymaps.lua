-- F9 for Compile and F10 for run CPP file
vim.api.nvim_create_autocmd("FileType", {
  pattern = "cpp",
  callback = function()
    -- Compile & Run for CPP
    vim.keymap.set("n", "<F9>", ":w<CR>:terminal bash compile.sh %:r<CR>a", { buffer = true })
    vim.keymap.set("n", "<F10>", ":w<CR>:terminal ./%:r<CR>a", { buffer = true })
  end
})

-- Exit terminal mode and go back to previous buffer
vim.api.nvim_create_autocmd("TermOpen", {
    callback = function(args)
        local bufnr= args.buf
        vim.keymap.set('t', '<Esc>', '<C-\\><C-n>:bp<CR>', {buffer = bufnr, noremap = true, silent = true})
    end
})

-- Text Moving
vim.keymap.set("v", ">", ">gv")
vim.keymap.set("v", "<", "<gv")
vim.keymap.set("v", "J", ":m '>+1<CR>gv=gv")
vim.keymap.set("v", "K", ":m '<-2<CR>gv=gv")


-- Mapping <leader> to space
vim.g.mapleader = " "
vim.g.localmapleader = " "

