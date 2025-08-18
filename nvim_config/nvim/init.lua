print('Welcome to NeoVim journey!')

-- Plugins
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim" 

if not (vim.uv or vim.loop).fs_stat(lazypath) then
    vim.fn.system({
        "git",
        "clone",
        "--filter=blob:none",
        "https://github.com/folke/lazy.nvim.git",
        "--branch=stable",
        lazypath
    })
end

local opts = {
    change_detection = {
        -- Don't notify everytime a change is made
        notify = false
    },
    checker = {
        -- Automatically check for updates
        enable = true,
        notify = false
    }
}


-- Add the path to the lazy plugin repositories to the vim runtime path
vim.opt.rtp:prepend(lazypath)

-- Load
require("config.options")
require("config.keymaps")
require("lazy").setup("plugins", opts)
